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

namespace Phalcon\Tests\Fixtures\Di;

use Phalcon\Html\Escaper\EscaperInterface;

/**
 * Class PropertiesComponent
 *
 * @package Phalcon\Tests\Fixtures\Di
 *
 * @property EscaperInterface $escaper
 * @property ServiceComponent $service
 */
class PropertiesComponent extends ServiceComponent
{
    private ?EscaperInterface $escaper = null;

    /**
     * @var string
     */
    public string $propertyName = '';

    /**
     * @var int
     */
    public int $propertyType = 0;

    /**
     * @var ServiceComponent
     */
    private ?ServiceComponent $service = null;

    /**
     * PropertiesComponent constructor.
     *
     * @param string $name
     * @param int    $type
     */
    public function __construct(
        string $name,
        int $type,
        EscaperInterface $escaper = null,
        ServiceComponent $service = null
    ) {
        $this->escaper = $escaper;
        $this->service = $service;

        parent::__construct($name, $type);
    }

    public function calculate(): void
    {
        $this->type = 555;
    }

    /**
     * @return EscaperInterface|null
     */
    public function getEscaper(): ?EscaperInterface
    {
        return $this->escaper;
    }

    /**
     * @return ?ServiceComponent
     */
    public function getService(): ?ServiceComponent
    {
        return $this->service;
    }

    /**
     * @param int $transformType
     */
    public function transform(int $transformType)
    {
        $this->type = $transformType;
    }
}
