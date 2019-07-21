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

namespace Phalcon\Test\Unit\Debug;

use UnitTester;

class ClearVarsCest
{
    /**
     * Tests Phalcon\Debug :: clearVars()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function debugClearVars(UnitTester $I)
    {
        $I->wantToTest('Debug - clearVars()');

        $I->skipTest('Need implementation');
    }
}
