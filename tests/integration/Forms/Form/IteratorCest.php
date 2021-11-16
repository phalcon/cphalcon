<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class IteratorCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    public function testIterator(IntegrationTester $I)
    {
        $form = new Form();
        $data = [];

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }

        $I->assertEquals(
            [],
            $data
        );


        $form->add(
            new Text('name')
        );

        $form->add(
            new Text('telephone')
        );

        foreach ($form as $key => $value) {
            $data[$key] = $value->getName();
        }

        $expected = [
            0 => 'name',
            1 => 'telephone',
        ];

        $I->assertEquals($expected, $data);
    }
}
