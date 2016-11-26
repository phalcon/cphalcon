<?php

namespace Phalcon\Build;

class Util
{
    /**
     * Normalize file path, convert all slashes to Linux-style and get rid of '..', '.'.
     *
     * @param $filePath
     * @return string
     */
    public static function normalize($filePath)
    {
        $filePath = realpath($filePath);
        $filePath = str_replace('\\', DIRECTORY_SEPARATOR, $filePath);

        return $filePath;
    }

    /**
     * Recursively deletes everything in the directory
     *
     * @param string $dir
     */
    public static function cleanDirectory($dir)
    {
        $iterator = new \DirectoryIterator($dir);
        foreach ($iterator as $entry) {
            /** @var $entry \DirectoryIterator */
            if ($entry->isDot() || $entry->getBasename() == 'tests') {
                continue;
            }

            if ($entry->isDir() && !$entry->isLink()) {
                self::cleanDirectory($entry->getPathname());
                rmdir($entry->getPathname());
            } else {
                if (is_writable($dir)) {
                    unlink($entry->getPathname());
                }
            }
        }
    }
}
