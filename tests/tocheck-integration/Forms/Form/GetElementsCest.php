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

class GetElementsCest
{
    /**
     * Tests Phalcon\Forms\Form :: getElements()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsFormGetElements(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getElements()');

        $form = new Form();

        $I->assertEquals(
            [],
            $form->getElements()
        );


        $name = new Text('name');

        $form->add($name);

        $I->assertEquals(
            [
                'name' => $name,
            ],
            $form->getElements()
        );


        $telephone = new Text('telephone');

        $form->add($telephone);

        $I->assertEquals(
            [
                'name'      => $name,
                'telephone' => $telephone,
            ],
            $form->getElements()
        );
    }
}
