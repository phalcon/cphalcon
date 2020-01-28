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

namespace Phalcon\Test\Unit\Http\Request\File;

use UnitTester;

class GetTypeCest
{
    /**
     * Tests Phalcon\Http\Request\File :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function httpRequestFileGetType(UnitTester $I)
    {
        $I->wantToTest('Http\Request\File - getType()');

        $I->skipTest('Need implementation');
    }
}
