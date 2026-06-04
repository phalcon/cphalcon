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
 */
final class FakeStreamAdapter extends Stream
{
    private bool $fileExists = true;

    private false | string $rawContents = '';

    public function __construct(Security $hasher)
    {
        parent::__construct($hasher, new StreamAdapterConfig('unused.json'));
    }

    public function setFileExists(bool $exists): void
    {
        $this->fileExists = $exists;
    }

    public function setRawContents(false | string $contents): void
    {
        $this->rawContents = $contents;
    }

    /**
     * Convenience: encode a list of user rows as the JSON payload Stream
     * expects on disk.
     *
     * @param array<int, array<string, mixed>> $users
     */
    public function setUsers(array $users): void
    {
        $this->rawContents = (string) json_encode($users);
        $this->fileExists  = true;
    }

    protected function phpFileExists(string $filename): bool
    {
        return $this->fileExists;
    }

    protected function phpFileGetContents(string $filename): false | string
    {
        return $this->rawContents;
    }
}
