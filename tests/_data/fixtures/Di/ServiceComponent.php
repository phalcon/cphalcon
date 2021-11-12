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

use Phalcon\Html\EscaperInterface;

/**
 * Class ServiceComponent
 *
 * @package Phalcon\Tests\Fixtures\Di
 *
 * @property string           $name
 * @property int              $type
 */
class ServiceComponent
{
    /**
     * @var string
     */
    protected string $name;

    /**
     * @var int
     */
    protected int $type;

    /**
     * PropertiesComponent constructor.
     *
     * @param string $name
     * @param int    $type
     */
    public function __construct(string $name, int $type)
    {
        $this->name = $name;
        $this->type = $type;
    }

    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * @return int
     */
    public function getType(): int
    {
        return $this->type;
    }
}
