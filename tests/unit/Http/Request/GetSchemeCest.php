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

class GetSchemeCest extends HttpBase
{
    /**
     * Tests getScheme default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestGetSchemeDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertEquals(
            'http',
            $request->getScheme()
        );
    }

    /**
     * Tests getScheme with HTTPS
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestGetScheme(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('HTTPS', 'on');
        $actual = $request->getScheme();
        $this->unsetServerVar('HTTPS');

        $I->assertEquals('https', $actual);
    }
}
