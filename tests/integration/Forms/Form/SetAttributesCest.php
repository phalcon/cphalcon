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

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Form;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Forms\Form :: setAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-11
     */
    public function formsFormSetAttributes(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - setAttributes()');

        $form = new Form();

        $actual = method_exists($form, 'setAttributes');

        $I->assertTrue($actual);
    }
}
