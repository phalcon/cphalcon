<?php

namespace Helper\Http;

/**
 * Helper\Http\PhpStream
 *
 * @link http://php.net/manual/en/class.streamwrapper.php
 * @link http://php.net/manual/en/stream.streamwrapper.example-1.php
 *
 * @codingStandardsIgnoreFile
 * @package Helper
 */
class PhpStream
{
    protected $index = 0;
    protected $length = 0;
    protected $data = '';

    public function __construct()
    {
        if (file_exists($this->getBufferFilename())) {
            $this->data = file_get_contents($this->getBufferFilename());
        }

        $this->index = 0;
        $this->length = strlen($this->data);
    }

    public function stream_open($path, $mode, $options, &$opened_path)
    {
        return true;
    }

    public function stream_close()
    {
    }

    public function stream_stat()
    {
        return [];
    }

    public function stream_flush()
    {
        return true;
    }

    public function stream_read($count)
    {
        if (null === $this->length) {
            $this->length = strlen($this->data);
        }

        $length = min($count, $this->length - $this->index);
        $data = substr($this->data, $this->index);
        $this->index = $this->index + $length;

        return $data;
    }

    public function stream_eof()
    {
        return ($this->index >= $this->length ? true : false);
    }

    public function stream_seek($offset, $whence)
    {
        if (null === $this->length) {
            $this->length = strlen($this->data);
        }

        switch ($whence) {
            case SEEK_SET:
                if ($offset < $this->length && $offset >= 0) {
                    $this->index = $offset;
                    return true;
                } else {
                    return false;
                }
            case SEEK_CUR:
                if ($offset >= 0) {
                    $this->index += $offset;
                    return true;
                } else {
                    return false;
                }
            case SEEK_END:
                if ($this->length + $offset >= 0) {
                    $this->index = $this->length + $offset;
                    return true;
                } else {
                    return false;
                }
            default:
                return false;
        }
    }

    public function stream_write($data)
    {
        return file_put_contents($this->getBufferFilename(), $data);
    }

    public function unlink()
    {
        if (file_exists($this->getBufferFilename())) {
            unlink($this->getBufferFilename());
        }

        $this->data = '';
        $this->index = 0;
        $this->length = 0;
    }

    protected function getBufferFilename()
    {
        return codecept_output_dir('tests/stream/php_input.txt');
    }
}
