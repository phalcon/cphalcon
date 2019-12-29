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
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;

/**
 * Class CountCest
 */
class CountCest
{
    /**
     * Tests Phalcon\Forms\Form :: count()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-18
     */
    public function formsFormCount(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - count()');

        $form = new Form();

        $I->assertCount(0, $form);

        $form->add(
            new Text('name')
        );

        $form->add(
            new Text('telephone')
        );

        $I->assertCount(2, $form);
    }
}
