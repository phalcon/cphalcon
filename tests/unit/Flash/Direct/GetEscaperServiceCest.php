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

namespace Phalcon\Test\Unit\Flash\Direct;

use UnitTester;

class GetEscaperServiceCest
{
    /**
     * Tests Phalcon\Flash\Direct :: getEscaperService()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashDirectGetEscaperService(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getEscaperService()');

        $I->skipTest('Need implementation');
    }
}
