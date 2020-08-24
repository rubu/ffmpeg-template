extern "C"
{
#include <libavformat/avformat.h>
}

#include <cstdlib>
#include <memory>
#include <stdexcept>
#include <iostream>

using AVFormatContextPtr = std::unique_ptr<AVFormatContext, decltype(&avformat_free_context)>;

class FFmpegException : public std::runtime_error
{
public:
    FFmpegException(int error) : std::runtime_error("ffmpeg exception"),
        error_(error)
    {
    }

private:
    int error_;
};

#define CHECK_AVERROR(x) { const auto result = (x); if (result < 0) { throw FFmpegException(result); }}

AVFormatContextPtr OpenInput(const char* url)
{
    AVFormatContext *format_context = nullptr;
    CHECK_AVERROR(avformat_open_input(&format_context, url, nullptr, nullptr));
    return AVFormatContextPtr(format_context, avformat_free_context);
}

int main(int argc, char **argv)
{
    try
    {
        if (argc == 2)
        {
            auto format_context = OpenInput(argv[1]);
        }
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }
    return EXIT_SUCCESS;
}