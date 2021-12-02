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

namespace Phalcon\Tests\Integration\Validation;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;

class GetSetFiltersCest
{
    /**
     * Tests Phalcon\Filter\Validation :: getFilters()/setFilters()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-27
     */
    public function filterValidationGetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getFilters()/setFilters()');

        $validation = new Validation();

        $validation
            ->add('name', new PresenceOf())
            ->add('email', new PresenceOf())
        ;

        $validation->setFilters('name', 'trim');
        $validation->setFilters('email', 'lower');

        $expected = [
            'name'  => 'trim',
            'email' => 'lower',
        ];
        $actual   = $validation->getFilters();
        $I->assertEquals($expected, $actual);
    }
}
