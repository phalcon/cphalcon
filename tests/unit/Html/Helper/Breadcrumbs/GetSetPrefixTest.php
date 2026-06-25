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

namespace Phalcon\Tests\Unit\Html\Helper\Breadcrumbs;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Breadcrumbs;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Url;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetSetPrefixTest extends AbstractUnitTestCase
{

    /**
     * Tests that the Url service injected in the constructor resolves links
     * through url->get(), which handles base URI prepending and double-slash
     * normalisation automatically.
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14957
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testHtmlHelperBreadcrumbsConstructWithUrlService(): void
    {
        $url = new Url();
        $url->setBaseUri('/myapp/');

        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper, $url);

        $breadcrumbs
            ->add('Home', '/')
            ->add('Invoices', '/invoices')
            ->add('List')
        ;

        // url->get('/') with baseUri '/myapp/' → '/myapp/' (double-slash removed)
        // url->get('/invoices') with baseUri '/myapp/' → '/myapp/invoices'
        $expected = "
<nav>
    <ol>
    <li><a href=\"/myapp/\">Home</a></li>
    <li>/</li>
    <li><a href=\"/myapp/invoices\">Invoices</a></li>
    <li>/</li>
    <li><span>List</span></li>

    </ol>
</nav>";

        $this->assertSame($expected, $breadcrumbs->render());
    }
    /**
     * Tests getPrefix() / setPrefix() without a Url service.
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14957
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testHtmlHelperBreadcrumbsGetSetPrefix(): void
    {
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);

        $this->assertSame('', $breadcrumbs->getPrefix());

        $breadcrumbs->setPrefix('/myapp');

        $this->assertSame('/myapp', $breadcrumbs->getPrefix());

        $breadcrumbs->setPrefix('');

        $this->assertSame('', $breadcrumbs->getPrefix());
    }

    /**
     * Tests that render() prepends the prefix string to every non-empty link.
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14957
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testHtmlHelperBreadcrumbsRenderWithPrefix(): void
    {
        $escaper     = new Escaper();
        $breadcrumbs = new Breadcrumbs($escaper);
        $breadcrumbs->setPrefix('/myapp');

        $breadcrumbs
            ->add('Home', '/')
            ->add('Invoices', '/invoices')
            ->add('List')
        ;

        $expected = "
<nav>
    <ol>
    <li><a href=\"/myapp/\">Home</a></li>
    <li>/</li>
    <li><a href=\"/myapp/invoices\">Invoices</a></li>
    <li>/</li>
    <li><span>List</span></li>

    </ol>
</nav>";

        $this->assertSame($expected, $breadcrumbs->render());
    }

    /**
     * Tests that TagFactory passes the Url service to Breadcrumbs so that
     * prefix is auto-configured without any manual setPrefix() call.
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14957
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testHtmlHelperBreadcrumbsTagFactoryWithUrlService(): void
    {
        $url = new Url();
        $url->setBaseUri('/myapp/');

        $escaper     = new Escaper();
        $factory     = new TagFactory($escaper, [], null, $url);
        $breadcrumbs = $factory->newInstance('breadcrumbs');

        $breadcrumbs
            ->add('Home', '/')
            ->add('Invoices', '/invoices')
            ->add('List')
        ;

        $expected = "
<nav>
    <ol>
    <li><a href=\"/myapp/\">Home</a></li>
    <li>/</li>
    <li><a href=\"/myapp/invoices\">Invoices</a></li>
    <li>/</li>
    <li><span>List</span></li>

    </ol>
</nav>";

        $this->assertSame($expected, $breadcrumbs->render());
    }
}
