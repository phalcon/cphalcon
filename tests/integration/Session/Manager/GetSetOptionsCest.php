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

namespace Phalcon\Tests\Integration\Session\Manager;

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetSetOptionsCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Manager :: getOptions()/setOptions() - constructor
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerGetSetOptionsConstructor(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getOptions()/setOptions() - constructor');

        $options = [
            'test1' => 'option1',
            'test2' => 'option2',
        ];

        $manager = new Manager($options);

        $actual = $manager->getOptions();
        $I->assertEquals($options, $actual);
    }

    /**
     * Tests Phalcon\Session\Manager :: getOptions()/setOptions()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionManagerGetSetOptions(IntegrationTester $I)
    {
        $I->wantToTest('Session\Manager - getOptions()/setOptions()');

        $options = [
            'test1' => 'option1',
            'test2' => 'option2',
        ];

        $manager = new Manager($options);
        $options = [
            'test3' => 'option3',
        ];


        $manager->setOptions($options);

        $actual = $manager->getOptions();
        $I->assertEquals($options, $actual);
    }
}
