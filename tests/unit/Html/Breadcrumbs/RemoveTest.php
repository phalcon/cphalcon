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

namespace Phalcon\Tests\Unit\Html\Breadcrumbs;

use Phalcon\Html\Breadcrumbs;
use Phalcon\Tests\AbstractUnitTestCase;

final class RemoveTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlBreadcrumbsRemove(): void
    {
        $breadcrumbs = new Breadcrumbs();

        $breadcrumbs
            ->add('Home', '/')
            ->add('Users', '/users')
            ->add('Phalcon Team')
        ;

        $this->assertSame(
            [
                '/'      => 'Home',
                '/users' => 'Users',
                ''       => 'Phalcon Team',
            ],
            $breadcrumbs->toArray()
        );

        $breadcrumbs->remove('/');

        $this->assertSame(
            [
                '/users' => 'Users',
                ''       => 'Phalcon Team',
            ],
            $breadcrumbs->toArray()
        );
    }
}
