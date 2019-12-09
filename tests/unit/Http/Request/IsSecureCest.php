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

class IsSecureCest extends HttpBase
{
    /**
     * Tests isSecure default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSecureDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertFalse(
            $request->isSecure()
        );
    }

    /**
     * Tests isSecure
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSecure(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('HTTPS', 'on');
        $actual = $request->isSecure();
        $this->unsetServerVar('HTTPS');

        $I->assertTrue($actual);
    }
}
