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
use Phalcon\Tests\Unit\Storage\Fake\WakeupCanary;

use function file_put_contents;
use function is_dir;
use function mkdir;
use function serialize;

final class GetPayloadObjectInjectionTest extends AbstractUnitTestCase
{
    /**
     * The stream payload read (getPayload) only ever holds a metadata array.
     * A crafted cache file that serializes an object must not be instantiated
     * on read, so its magic methods cannot fire (CWE-502).
     */
    public function testStorageAdapterStreamGetPayloadRejectsObjectInjection(): void
    {
        $serializer = new SerializerFactory();
        $adapter    = new Stream(
            $serializer,
            [
                'storageDir' => Talon::settings()->outputPath() . '/',
            ]
        );

        $target = Talon::settings()->outputPath('ph-strm/te/st/-k/');
        if (true !== is_dir($target)) {
            mkdir($target, 0777, true);
        }

        /**
         * Simulate an attacker who can write the cache file: plant a serialized
         * object at the key's path.
         */
        WakeupCanary::$fired = false;

        file_put_contents(
            $target . 'test-key',
            serialize(new WakeupCanary())
        );

        $actual = $adapter->get('test-key', 'default');

        $this->assertFalse(WakeupCanary::$fired);
        $this->assertSame('default', $actual);

        $this->safeDeleteFile($target . 'test-key');
    }
}
