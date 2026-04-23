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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Tests\AbstractUnitTestCase;

class GetSetOptionsTest extends AbstractUnitTestCase
{
    /**
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function testMvcViewEngineVoltGetSetOptions(): void
    {
        $view    = new View();
        $volt    = new Volt($view);
        $options = [
            'path'      => '../app/compiled-templates/',
            'extension' => '.compiled',
        ];

        $volt->setOptions($options);

        $expected = $options;
        $actual   = $volt->getOptions();
        $this->assertSame($expected, $actual);
    }
}
