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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Stream;

use Phalcon\Annotations\Adapter\Stream;
use Phalcon\Annotations\Reader;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;

final class GetSetReaderTest extends AbstractUnitTestCase
{
    /**
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function testAnnotationsAdapterStreamGetSetReader(): void
    {
        $adapter = new Stream(
            [
                'annotationsDir' => Talon::settings()->outputPath('tests/annotations/'),
            ]
        );

        $reader = new Reader();
        $adapter->setReader($reader);

        $this->assertSame($reader, $adapter->getReader());
        $this->assertInstanceOf(Reader::class, $adapter->getReader());
    }
}
