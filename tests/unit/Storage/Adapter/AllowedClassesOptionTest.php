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

use FilesystemIterator;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Unit\Storage\Fake\WakeupCanary;
use RecursiveDirectoryIterator;
use RecursiveIteratorIterator;
use SplFileInfo;
use stdClass;

use function dirname;
use function file_get_contents;
use function file_put_contents;
use function fileperms;
use function is_dir;
use function serialize;
use function umask;
use function unserialize;

/**
 * The "allowedClasses" adapter option is handed to the "php" serializer, so
 * stored bytes cannot build arbitrary objects on read - including the
 * nested content of the Stream adapter, whose envelope guard alone does not
 * cover it.
 */
final class AllowedClassesOptionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageAdapterAllowedClassesOptionReachesSerializer(): void
    {
        $adapter = new Memory(new SerializerFactory(), ['allowedClasses' => false]);

        $this->assertFalse($adapter->getSerializer()->getAllowedClasses());

        $adapter = new Memory(new SerializerFactory(), ['allowedClasses' => [stdClass::class]]);

        $this->assertSame([stdClass::class], $adapter->getSerializer()->getAllowedClasses());
        $adapter->set('key', new stdClass());
        $this->assertInstanceOf(stdClass::class, $adapter->get('key'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageAdapterMemoryRejectsObjectsWhenAllowedClassesIsFalse(): void
    {
        $adapter = new Memory(new SerializerFactory(), ['allowedClasses' => false]);

        WakeupCanary::$fired = false;
        $adapter->set('key', new WakeupCanary());

        $this->assertSame('default', $adapter->get('key', 'default'));
        $this->assertFalse(WakeupCanary::$fired);
    }

    /**
     * Shard directories are created with mode 0755 (before umask), not 0777.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageAdapterStreamCreatesDirectoriesWithoutWorldWrite(): void
    {
        $adapter = new Stream(
            new SerializerFactory(),
            ['storageDir' => Talon::settings()->outputPath() . '/']
        );

        $adapter->set('perm-key', 'value');

        $file = $this->findStoredFile('perm-key');
        $this->assertNotNull($file);
        $directory = dirname($file);
        $this->assertTrue(is_dir($directory));
        $this->assertSame(0755 & ~umask(), fileperms($directory) & 0777);

        $adapter->delete('perm-key');
    }

    /**
     * A crafted cache file with a valid envelope and an object in the
     * nested content must not instantiate the object on read.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageAdapterStreamNestedContentHonorsAllowedClasses(): void
    {
        $adapter = new Stream(
            new SerializerFactory(),
            [
                'storageDir'     => Talon::settings()->outputPath() . '/',
                'allowedClasses' => false,
            ]
        );

        $adapter->set('nested-key', 'benign');

        $file = $this->findStoredFile('nested-key');
        $this->assertNotNull($file);
        $envelope = unserialize(file_get_contents($file), ['allowed_classes' => false]);
        $this->assertIsArray($envelope);

        $envelope['content'] = serialize(new WakeupCanary());
        file_put_contents($file, serialize($envelope));

        WakeupCanary::$fired = false;
        $actual              = $adapter->get('nested-key', 'default');

        $this->safeDeleteFile($file);

        $this->assertFalse(WakeupCanary::$fired);
        $this->assertSame('default', $actual);
    }

    /**
     * Returns the path of the file the Stream adapter wrote for the key
     */
    private function findStoredFile(string $key): ?string
    {
        $iterator = new RecursiveIteratorIterator(
            new RecursiveDirectoryIterator(
                Talon::settings()->outputPath('ph-strm'),
                FilesystemIterator::SKIP_DOTS
            )
        );

        /** @var SplFileInfo $entry */
        foreach ($iterator as $entry) {
            if ($entry->isFile() && $entry->getFilename() === $key) {
                return $entry->getPathname();
            }
        }

        return null;
    }
}
