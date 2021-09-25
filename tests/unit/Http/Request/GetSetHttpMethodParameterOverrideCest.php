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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Http\Request;
use UnitTester;

class GetSetHttpMethodParameterOverrideCest
{
    /**
     * Tests Phalcon\Http\Request ::
     * getHttpMethodParameterOverride()/setHttpMethodParameterOverride()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetSetHttpMethodParameterOverride(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getHttpMethodParameterOverride()/setHttpMethodParameterOverride()');

        $request = new Request();

        $I->assertFalse($request->getHttpMethodParameterOverride());

        $request->setHttpMethodParameterOverride(true);
        $I->assertTrue($request->getHttpMethodParameterOverride());
    }
}
