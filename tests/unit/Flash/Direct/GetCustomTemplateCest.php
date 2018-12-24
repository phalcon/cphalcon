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

namespace Phalcon\Test\Unit\Flash\Direct;

use UnitTester;

/**
 * Class GetCustomTemplateCest
 */
class GetCustomTemplateCest
{
    /**
     * Tests Phalcon\Flash\Direct :: getCustomTemplate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function flashDirectGetCustomTemplate(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getCustomTemplate()');
        $I->skipTest('Need implementation');
    }
}
