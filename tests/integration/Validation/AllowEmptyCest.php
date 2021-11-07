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
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;

class AllowEmptyCest
{
    /**
     * Tests Phalcon\Validation :: allowEmpty()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function validationAllowEmptyFalse(IntegrationTester $I)
    {
        $I->wantToTest('Validation - allowEmpty() - false');

        $data = ['name' => ''];
        $validation = new Validation();
        $validator = new Alpha(['allowEmpty' => false]);
        $validation->add('name', $validator);
        $messages = $validation->validate($data);

        $I->assertCount(0, $messages);
    }

    public function validationAllowEmptyTrue(IntegrationTester $I)
    {
        $I->wantToTest('Validation - allowEmpty() - true');

        $data = ['name' => ''];
        $validation = new Validation();
        $validator = new Alpha(['allowEmpty' => true]);
        $validation->add('name', $validator);
        $messages = $validation->validate($data);

        $I->assertCount(0, $messages);
    }
}
