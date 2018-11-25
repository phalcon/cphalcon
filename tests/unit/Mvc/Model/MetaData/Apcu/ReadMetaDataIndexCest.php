<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Apcu;

use UnitTester;

class ReadMetaDataIndexCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Apcu :: readMetaDataIndex()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataApcuReadMetaDataIndex(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\MetaData\Apcu - readMetaDataIndex()");
        $I->skipTest("Need implementation");
    }
}
