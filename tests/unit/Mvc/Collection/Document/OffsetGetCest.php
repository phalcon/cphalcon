<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Collection\Document;

use UnitTester;

/**
 * Class OffsetGetCest
 *
 * @package Phalcon\Test\Unit\Mvc\Collection\Document
 */
class OffsetGetCest
{
    /**
     * Tests Phalcon\Mvc\Collection\Document :: offsetGet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcCollectionDocumentOffsetGet(UnitTester $I)
    {
        $I->wantToTest("Mvc\Collection\Document - offsetGet()");
        $I->skipTest("Need implementation");
    }
}
