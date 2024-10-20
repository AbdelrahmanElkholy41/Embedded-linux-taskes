#!/bin/bash



# YouTube video URL from command line
VIDEO_URL=$1

# Optional output directory (defaults to current directory)
OUTPUT_DIR=${2:-$(pwd)}

# Check if yt-dlp is installed
if ! command -v yt-dlp &> /dev/null; then
    echo "yt-dlp could not be found, please install it first."
    exit 1
fi

# Download the video
yt-dlp -o "$OUTPUT_DIR/%(title)s.%(ext)s" "$VIDEO_URL"

echo "Download complete! Saved to $OUTPUT_DIR."
