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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class IsAjaxCest extends HttpBase
{
    /**
     * Tests isAjax default
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsAjax(UnitTester $I)
    {
        $this->setServerVar('HTTP_X_REQUESTED_WITH', 'XMLHttpRequest');

        $request = $this->getRequestObject();

        $actual = $request->isAjax();
        $this->unsetServerVar('HTTP_X_REQUESTED_WITH');

        $I->assertTrue($actual);
    }
}
