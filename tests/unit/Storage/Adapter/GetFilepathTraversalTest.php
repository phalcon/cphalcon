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

final class GetFilepathTraversalTest extends AbstractUnitTestCase
{
    /**
     * A crafted key must not climb out of the storage directory: the key
     * becomes the file name, so its path separators have to be removed (CWE-22).
     */
    public function testStorageAdapterStreamGetFilepathNeutralizesTraversal(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => Talon::settings()->outputPath() . '/',
            ]
        );

        $method = new ReflectionMethod($adapter, 'getFilepath');
        $method->setAccessible(true);

        $actual = $method->invoke($adapter, '../../../../pwned');

        $this->assertStringNotContainsString('../', $actual);
    }
}
