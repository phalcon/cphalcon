<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Http;

/**
 * @link http://php.net/manual/en/class.streamwrapper.php
 * @link http://php.net/manual/en/stream.streamwrapper.example-1.php
 *
 * @codingStandardsIgnoreFile
 */
class PhpStream
{
    /**
     * @var int
     */
    protected $index = 0;

    /**
     * @var int
     */
    protected $length = 0;

    /**
     * @var string
     */
    protected $data = '';

    public function __construct()
    {
        if (file_exists($this->getBufferFilename())) {
            $this->data = file_get_contents(
                $this->getBufferFilename()
            );
        }

        $this->index  = 0;
        $this->length = strlen($this->data);
    }

    protected function getBufferFilename(): string
    {
        return codecept_output_dir('tests/stream/php_input.txt');
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

        $length = min(
            $count,
            $this->length - $this->index
        );

        $data        = substr($this->data, $this->index);
        $this->index = $this->index + $length;

        return $data;
    }

    public function stream_eof()
    {
        return ($this->index >= $this->length);
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
        return file_put_contents(
            $this->getBufferFilename(),
            $data
        );
    }

    public function unlink()
    {
        if (file_exists($this->getBufferFilename())) {
            unlink(
                $this->getBufferFilename()
            );
        }

        $this->data   = '';
        $this->index  = 0;
        $this->length = 0;
    }
}
