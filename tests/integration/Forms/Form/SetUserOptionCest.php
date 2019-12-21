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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Form;

class SetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Form :: setUserOption()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsFormSetUserOption(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - setUserOption()');

        $form = new Form();

        $form->setUserOption('some', 'value');

        $I->assertEquals(
            'value',
            $form->getUserOption('some')
        );
    }
}
