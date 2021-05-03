<?php

declare(strict_types=1);

namespace Phalcon\Build;

use DirectoryIterator;

class Util
{
    /**
     * Normalize file path, convert all slashes to Linux-style and get rid of '..', '.'.
     *
     * @param string $filePath
     * @return string|null
     */
    public static function normalize(string $filePath): ?string
    {
        $filePath = realpath($filePath);
        if ($filePath === false) {
            return null;
        }

        return str_replace('\\', DIRECTORY_SEPARATOR, $filePath);
    }

    /**
     * Recursively deletes everything in the directory
     *
     * @param string $dir
     */
    public static function cleanDirectory(string $dir): void
    {
        $iterator = new DirectoryIterator($dir);
        foreach ($iterator as $entry) {
            /** @var $entry DirectoryIterator */
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
