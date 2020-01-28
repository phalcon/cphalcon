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

namespace Phalcon\Test\Unit\Flash\Session;

use UnitTester;

class SetAutoescapeCest
{
    /**
     * Tests Phalcon\Flash\Session :: setAutoescape()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function flashSessionSetAutoescape(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - setAutoescape()');

        $I->skipTest('Need implementation');
    }
}
