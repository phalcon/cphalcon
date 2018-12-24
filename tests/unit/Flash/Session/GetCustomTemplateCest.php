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

namespace Phalcon\Test\Unit\Flash\Session;

use UnitTester;

/**
 * Class GetCustomTemplateCest
 */
class GetCustomTemplateCest
{
    /**
     * Tests Phalcon\Flash\Session :: getCustomTemplate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashSessionGetCustomTemplate(UnitTester $I)
    {
        $I->wantToTest('Flash\Session - getCustomTemplate()');
        $I->skipTest('Need implementation');
    }
}
