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

namespace Phalcon\Tests\Unit\Mvc\Model\MetaData\Stream;

use Phalcon\Mvc\Model\MetaData\Stream;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

use function glob;

final class ReadWriteTest extends AbstractUnitTestCase
{
    /**
     * "meta-A\\B" and "meta-A_B" both normalize to "meta-a_b"; the second
     * gets a hash suffix so the two never share a cache file.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelMetaDataStreamReadWriteNoCollision(): void
    {
        $dir     = Talon::settings()->outputPath('tests/cache/');
        $adapter = new Stream(['metaDataDir' => $dir]);

        $adapter->write('meta-A\\B', ['x' => 1]);
        $adapter->write('meta-A_B', ['x' => 2]);

        $first  = $adapter->read('meta-A\\B');
        $second = $adapter->read('meta-A_B');

        foreach (glob($dir . 'meta-a_b*.php') as $file) {
            $this->safeDeleteFile($file);
        }

        $this->assertSame(['x' => 1], $first);
        $this->assertSame(['x' => 2], $second);
    }
}
