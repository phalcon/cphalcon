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

class GetUserOptionCest
{
    /**
     * Tests Phalcon\Forms\Form :: getUserOption()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsFormGetUserOption(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getUserOption()');

        $userOptions = [
            'some' => 'value',
        ];

        $form = new Form();

        $form->setUserOptions($userOptions);

        $I->assertEquals(
            $userOptions,
            $form->getUserOptions()
        );

        $I->assertEquals(
            'value',
            $form->getUserOption('some')
        );

        $I->assertNull(
            $form->getUserOption('some-non')
        );
    }

    /**
     * Tests Phalcon\Forms\Form :: getUserOption() with default value
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsFormGetUserOptionDefaultValue(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getUserOption() with default value');

        $form = new Form();

        $form->setUserOption('some', 'value');

        $I->assertEquals(
            'value',
            $form->getUserOption('some', 'default')
        );

        $I->assertEquals(
            'default',
            $form->getUserOption('some-non', 'default')
        );
    }
}
