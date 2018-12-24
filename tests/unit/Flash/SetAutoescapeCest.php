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

namespace Phalcon\Test\Unit\Flash;

use UnitTester;

/**
 * Class SetAutoescapeCest
 */
class SetAutoescapeCest
{
    /**
     * Tests Phalcon\Flash :: setAutoescape()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashSetAutoescape(UnitTester $I)
    {
        $I->wantToTest('Flash - setAutoescape()');
        $I->skipTest('Need implementation');
    }
}
