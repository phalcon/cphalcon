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
use UnitTester;

class GetSetReaderCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: getReader() / setReader()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-01-22
     */
    public function annotationsAdapterStreamGetSetReader(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - getReader() / setReader()');

        $oAdapter = new Stream(
            [
                'annotationsDir' => outputDir('tests/annotations/'),
            ]
        );

        $oReader = new Reader();
        $oAdapter->setReader($oReader);

        $I->assertSame(
            $oReader,
            $oAdapter->getReader()
        );

        $oClass  = Reader::class;
        $oActual = $oAdapter->getReader();
        $I->assertInstanceOf($oClass, $oActual);
    }
}
