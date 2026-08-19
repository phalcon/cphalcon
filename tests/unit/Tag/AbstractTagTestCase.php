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

namespace Phalcon\Tests\Unit\Tag;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Mvc\Url;
use Phalcon\Tag;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

/**
 * Tag holds every setting it is handed in a static property, so anything a
 * test changes survives into the next one unless the whole set is put back.
 *
 * The reset restores the declared defaults instead of calling
 * Tag::resetInput(), which nulls the title properties rather than emptying
 * them and leaves the services and the doctype alone.
 */
abstract class AbstractTagTestCase extends AbstractUnitTestCase
{
    protected const BASE_URI = 'https://phalcon.io/';

    protected function setUp(): void
    {
        parent::setUp();

        $this->resetTag();

        Tag::setDI($this->newContainer());
        Tag::setDocType(Tag::HTML5);
        Tag::setAutoescape(false);
    }

    protected function tearDown(): void
    {
        $this->resetTag();

        parent::tearDown();
    }

    /**
     * A container carrying the two services the helpers reach for.
     */
    protected function newContainer(): Di
    {
        $url = new Url();
        $url->setBaseUri(self::BASE_URI);

        $container = new Di();
        $container->setShared('escaper', new Escaper());
        $container->setShared('url', $url);

        return $container;
    }

    protected function resetTag(): void
    {
        $_POST = [];

        $this->setProtectedProperty(Tag::class, 'autoEscape', true);
        $this->setProtectedProperty(Tag::class, 'container', null);
        $this->setProtectedProperty(Tag::class, 'displayValues', []);
        $this->setProtectedProperty(Tag::class, 'documentAppendTitle', []);
        $this->setProtectedProperty(Tag::class, 'documentPrependTitle', []);
        $this->setProtectedProperty(Tag::class, 'documentTitle', '');
        $this->setProtectedProperty(Tag::class, 'documentTitleSeparator', '');
        $this->setProtectedProperty(Tag::class, 'documentType', Tag::XHTML5);
        $this->setProtectedProperty(Tag::class, 'escaperService', null);
        $this->setProtectedProperty(Tag::class, 'urlService', null);
    }
}
