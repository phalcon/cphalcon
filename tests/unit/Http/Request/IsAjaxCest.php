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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class IsAjaxCest extends HttpBase
{
    /**
     * Tests isAjax default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjaxDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertFalse(
            $request->isAjax()
        );
    }

    /**
     * Tests isAjax
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjax(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('HTTP_X_REQUESTED_WITH', 'XMLHttpRequest');
        $actual = $request->isAjax();
        $this->unsetServerVar('HTTP_X_REQUESTED_WITH');

        $I->assertTrue($actual);
    }
}
