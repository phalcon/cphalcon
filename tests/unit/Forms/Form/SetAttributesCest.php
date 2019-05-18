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

namespace Phalcon\Test\Unit\Forms\Form;

use Phalcon\Forms\Form;
use UnitTester;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Forms\Form :: setAttributes()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-11
     */
    public function formsFormSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Forms\Form - setAttributes()');

        $form = new Form();

        $actual = method_exists($form, 'setAttributes');

        $I->assertTrue($actual);
    }
}
