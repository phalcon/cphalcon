<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Auth\Fake;

use Phalcon\Auth\Adapter\Config\StreamAdapterConfig;
use Phalcon\Auth\Adapter\Stream;
use Phalcon\Contracts\Encryption\Security\Security;

/**
 * Fakes the disk side of Phalcon\Auth\Adapter\Stream by overriding the
 * FileTrait helpers. This lets the real Stream::loadUsers logic execute
 * (including the JSON decode + shape checks) under test, while the test
 * controls what bytes are "read" from disk.
 *
 * The FileTrait wrappers are static, so the configured state lives in static
 * properties; the constructor resets them so each new instance starts clean.
 */
final class FakeStreamAdapter extends Stream
{
    private static bool $fileExists = true;

    private static false | string $rawContents = '';

    public function __construct(Security $hasher)
    {
        self::$fileExists  = true;
        self::$rawContents = '';

        parent::__construct($hasher, new StreamAdapterConfig('unused.json'));
    }

    public function setFileExists(bool $exists): void
    {
        self::$fileExists = $exists;
    }

    public function setRawContents(false | string $contents): void
    {
        self::$rawContents = $contents;
    }

    /**
     * Convenience: encode a list of user rows as the JSON payload Stream
     * expects on disk.
     *
     * @param array<int, array<string, mixed>> $users
     */
    public function setUsers(array $users): void
    {
        self::$rawContents = (string) json_encode($users);
        self::$fileExists  = true;
    }

    protected static function phpFileExists(string $filename): bool
    {
        return self::$fileExists;
    }

    protected static function phpFileGetContents(
        string $filename,
        bool $useIncludePath = false,
        $context = null,
        int $offset = 0,
        ?int $length = null
    ): false | string {
        return self::$rawContents;
    }
}
