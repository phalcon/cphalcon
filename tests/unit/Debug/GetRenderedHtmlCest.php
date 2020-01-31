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

namespace Phalcon\Test\Unit\Debug;

use UnitTester;
use Phalcon\Debug;

class GetRenderedHtmlCest
{
    /**
     * Tests Phalcon\Debug :: renderHtml()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function debugDebugVar(UnitTester $I)
    {
        $I->wantToTest('Debug - renderHtml()');

        /*
         * Let's make sure there are no exceptions.
         */
        Debug::renderHtml(new \Exception());

        $I->skipTest('Need implementation');
    }
}