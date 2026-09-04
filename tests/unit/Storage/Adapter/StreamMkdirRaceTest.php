<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Storage\Adapter;

use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Storage\Fake\FakeStreamIsDir;

use function error_clear_last;
use function error_get_last;

final class StreamMkdirRaceTest extends AbstractUnitTestCase
{
    /**
     * FakeStreamIsDir always reports that the directory is absent. The mkdir()
     * call that follows the first set() thus finds the directory on the disk
     * and fails with "File exists" - the same result as a different process
     * that makes the directory first. The adapter must ignore that condition:
     * the write goes through, no warning comes out and no error stays behind.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-04
     */
    public function testStorageAdapterStreamSetIgnoresConcurrentDirectoryCreation(): void
    {
        $adapter = new FakeStreamIsDir(
            new SerializerFactory(),
            ['storageDir' => Talon::settings()->outputPath() . '/']
        );

        $adapter->set('mkdir-race', 'one');

        error_clear_last();
        $actual    = $adapter->set('mkdir-race', 'two');
        $lastError = error_get_last();
        $stored    = $adapter->get('mkdir-race');

        $adapter->delete('mkdir-race');
        $this->safeDeleteDirectory(Talon::settings()->outputPath('ph-strm'));

        $this->assertTrue($actual);
        $this->assertNull($lastError);
        $this->assertSame('two', $stored);
    }
}
