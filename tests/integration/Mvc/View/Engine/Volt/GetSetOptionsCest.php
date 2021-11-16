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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Mvc\View\Engine\Volt;

class GetSetOptionsCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: getOptions() / setOptions()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEngineVoltGetSetOptions(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - getOptions() / setOptions()');

        $view = new View();

        $volt = new Volt($view);


        $options = [
            'path'      => '../app/compiled-templates/',
            'extension' => '.compiled',
        ];

        $volt->setOptions($options);

        $I->assertEquals(
            $options,
            $volt->getOptions()
        );
    }
}
