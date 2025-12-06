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

namespace Phalcon\Tests\Integration\Filter\Validation;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

use function date;
use function intval;
use function uniqid;

class GetSetLabelCest
{
    /**
     * Tests Phalcon\Filter\Validation :: getLabel()/setLabels()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function filterValidationGetLabel(IntegrationTester $I): void
    {
        $I->wantToTest('Validation - getLabel()');
        $validator  = new PresenceOf();
        $validation = new Validation();

        $validation->bind(
            new stdClass(),
            [
                'day'   => date('d'),
                'month' => date('m'),
                'year'  => (string)(intval(date('Y')) + 1),
            ]
        );

        $label = uniqid('lbl-');
        $validation->setLabels(
            [
                'foo' => $label,
            ]
        );
        $validator->validate($validation, 'foo');

        $expected = $label;
        $actual = $validation->getLabel('foo');
        $I->assertSame($expected, $actual);
    }
}
