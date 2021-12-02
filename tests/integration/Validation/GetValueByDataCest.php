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
use Phalcon\Tests\Models\EntityWithPublic;
use Phalcon\Filter\Validation;

/**
 * Class GetValueByDataCest
 */
class GetValueByDataCest
{
    public const NAME = 'John Doe';

    /**
     * Tests Phalcon\Filter\Validation :: getValueByData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-11-07
     */
    public function filterValidationGetValueByDataArray(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValueByData()');

        $data = [
            'name' => self::NAME,
        ];

        $validation = new Validation();
        $value = $validation->getValueByData($data, 'name');

        $I->assertSame($data['name'], $value);
    }

    public function filterValidationGetValueByDataObject(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValueByData()');

        $data = new EntityWithPublic(self::NAME);

        $validation = new Validation();
        $value = $validation->getValueByData($data, 'name');

        $I->assertSame($data->name, $value);
    }
}
