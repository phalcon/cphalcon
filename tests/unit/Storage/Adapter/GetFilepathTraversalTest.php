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

use Phalcon\Storage\Adapter\Stream;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use ReflectionMethod;

use function basename;

final class GetFilepathTraversalTest extends AbstractUnitTestCase
{
    /**
     * The key becomes the file name, so its case must survive. A lower-cased
     * name no longer matches the file that was written.
     */
    public function testStorageAdapterStreamGetFilepathKeepsTheKeyCase(): void
    {
        $actual = $this->getFilepath('MyKey');

        $this->assertSame('MyKey', basename($actual));
        $this->assertStringNotContainsString('mykey', $actual);
    }

    /**
     * A Windows style separator must not climb out of the storage directory
     * either (CWE-22).
     */
    public function testStorageAdapterStreamGetFilepathNeutralizesBackslash(): void
    {
        $actual = $this->getFilepath('..\..\pwned');

        $this->assertSame('.._.._pwned', basename($actual));
        $this->assertStringNotContainsString('\\', $actual);
        $this->assertStringStartsWith($this->getStorageDir(), $actual);
    }

    /**
     * A `:` in the key must go as well, otherwise the file name turns into a
     * stream wrapper URL.
     */
    public function testStorageAdapterStreamGetFilepathNeutralizesStreamWrapper(): void
    {
        $actual = $this->getFilepath('php://filter');

        $this->assertSame('php___filter', basename($actual));
        $this->assertStringNotContainsString(':', $actual);
        $this->assertStringStartsWith($this->getStorageDir(), $actual);
    }

    /**
     * A crafted key must not climb out of the storage directory: the key
     * becomes the file name, so its path separators have to be removed (CWE-22).
     */
    public function testStorageAdapterStreamGetFilepathNeutralizesTraversal(): void
    {
        $actual = $this->getFilepath('../../../../pwned');

        $this->assertStringNotContainsString('../', $actual);
    }

    private function getFilepath(string $key): string
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => $this->getStorageDir(),
            ]
        );

        $method = new ReflectionMethod($adapter, 'getFilepath');
        $method->setAccessible(true);

        return $method->invoke($adapter, $key);
    }

    private function getStorageDir(): string
    {
        return Talon::settings()->outputPath() . '/';
    }
}
