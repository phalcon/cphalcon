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

use UnitTester;

class SetParameterFiltersCest
{
    /**
     * Unit Tests Phalcon\Http\Request :: setParameterFilters()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function httpRequestSetParameterFilters(UnitTester $I)
    {
        $I->wantToTest('Http\Request - setParameterFilters()');

        $I->skipTest('Need implementation');
    }
}
