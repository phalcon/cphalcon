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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\Test;
use stdClass;

use function date;
use function intval;
use function uniqid;

final class GetSetLabelTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function testFilterValidationGetLabel(): void
    {
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

        $label1 = uniqid('lbl-');
        $label2 = uniqid('lbl-');
        $validation->setLabels(
            [
                'name' => $label1,
                'city' => $label2,
            ]
        );
        $validator->validate($validation, 'name');

        $expected = $label1;
        $actual   = $validation->getLabel('name');
        $this->assertSame($expected, $actual);

        $expected = 'unknown';
        $actual   = $validation->getLabel('unknown');
        $this->assertSame($expected, $actual);

        $expected = 'name, email';
        $actual   = $validation->getLabel(['name', 'email']);
        $this->assertSame($expected, $actual);
    }
}
