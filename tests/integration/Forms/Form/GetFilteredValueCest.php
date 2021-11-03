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
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;

/**
 * Class GetFilteredValueCest
 */
class GetFilteredValueCest
{
    /**
     * Tests Phalcon\Forms\Form :: getFilteredValue()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-03
     */
    public function testGetFilteredValueWithoutEntity(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getFilteredValue()');

        $data = [
            'firstName' => ' test ',
            'lastName' => ' test   123 33 ',
        ];

        $form = $this->getForm($data, null);

        $I->assertEquals($data['firstName'], $form->getValue("firstName"));
        $I->assertEquals($data['lastName'], $form->getValue("lastName"));
        $I->assertEquals("test", $form->getFilteredValue("firstName"));
        $I->assertEquals("test 123 33", $form->getFilteredValue("lastName"));
    }

    public function testGetFilteredValueWithEntity(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getFilteredValue()');

        $entity = new \stdClass();
        $data = [
            'firstName' => ' test ',
            'lastName' => ' test   123 33 ',
        ];

        $form = $this->getForm($data, $entity);

        $I->assertEquals($data['firstName'], $form->getValue("firstName"));
        $I->assertEquals($data['lastName'], $form->getValue("lastName"));
        $I->assertEquals("test", $form->getFilteredValue("firstName"));
        $I->assertEquals("test 123 33", $form->getFilteredValue("lastName"));
    }

    private function getForm(array $data, $entity = null): Form
    {
        $form = new Form();
        $firstNameTag = new Text('firstName');
        $lastNameTag = new Text('lastName');
        $form->add(
            $firstNameTag->setFilters([
                'upper',
                'regex' => ["/^\s+|\s+$|\s+(?=\s)/", ''],
            ])->setLabel('Firstname')
        );
        $form->add(
            $lastNameTag->setFilters([
                'upper',
                'regex' => ["/^\s+|\s+$|\s+(?=\s)/", ''],
            ])->setLabel('Lastname')
        );

        $whiteList = [];
        $form->bind($data, $entity, $whiteList);

        return $form;
    }
}
