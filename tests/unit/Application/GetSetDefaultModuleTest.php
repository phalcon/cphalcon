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

namespace Phalcon\Tests\Unit\Application;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Application\Fake\FakeApplication;

final class GetSetDefaultModuleTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testApplicationGetSetDefaultModule(): void
    {
        $application = new FakeApplication();

        $expected = '';
        $actual   = $application->getDefaultModule();
        $this->assertSame($expected, $actual);

        $application->setDefaultModule('admin');

        $expected = 'admin';
        $actual   = $application->getDefaultModule();
        $this->assertSame($expected, $actual);
    }
}
