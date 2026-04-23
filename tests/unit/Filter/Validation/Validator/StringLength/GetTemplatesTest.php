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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength;

use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetTemplatesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthGetTemplates(): void
    {
        $validator = new StringLength();

        $expected = [];
        $actual   = $validator->getTemplates();
        $this->assertSame($expected, $actual, 'Default templates is empty array');

        $templates = [
            'field1' => 'Template for field1',
            'field2' => 'Template for field2',
        ];
        $validator->setTemplates($templates);

        $expected = $templates;
        $actual   = $validator->getTemplates();
        $this->assertSame($expected, $actual, 'Returns templates after setTemplates()');
    }
}
