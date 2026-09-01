
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Auth\Internal;

use Closure;
use Phalcon\Container\Exceptions\Exception as ContainerException;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Exception as DiException;
use Phalcon\Di\Service;
use TypeError;

/**
 * Internal single source of truth for resolving services from either the
 * new Phalcon\Container\Container or the legacy Phalcon\Di\Di. Not part of
 * the public API.
 *
 * Intent is Container-first; the legacy Di is supported "with provisions":
 * definitions must be pre-registered (no autowiring), the one exception
 * being the fresh path, which lets Di build an unregistered but existing
 * class via its class builder.
 *
 * All legacy-Di failures are normalized to Phalcon\Container\Exceptions so
 * callers and userland catch a single exception family.
 */
final class ContainerResolver
{
    /**
     * Validates that the value is a supported container.
     *
     * @throws TypeError
     */
    public static function ensureContainer(var container) -> void
    {
        if (!(container instanceof Collection) && !(container instanceof DiInterface)) {
            throw new TypeError(
                "The parameter must be an instance of Collection or DiInterface"
            );
        }
    }

    /**
     * Resolves the first candidate service name that the container can
     * provide, as a shared instance. Used for framework services (request,
     * cookies, session) whose container key may vary between application
     * setups.
     *
     * @param list<string> $candidates
     *
     * @throws ContainerException
     */
    public static function requireService(var container, array candidates, string context) -> object
    {
        self::ensureContainer(container);

        var name;

        for name in candidates {
            if (container->has(name)) {
                return self::resolveShared(container, name);
            }
        }

        throw new ContainerException(
            "Auth " . context . " requires service. None of the following are "
            . "bound in the container: " . implode(", ", candidates)
        );
    }

    /**
     * Convenience composition of serviceCandidates() + requireService():
     * resolves the first bound candidate for a framework service whose
     * container key may vary, using the options override or the
     * [interface FQN, conventional short name] fallback.
     *
     * @param array<string, mixed> $options
     *
     * @throws ContainerException
     */
    public static function resolveCandidate(
        var container,
        array options,
        string key,
        string fqn,
        string shortName,
        string context
    ) -> object {
        return self::requireService(
            container,
            self::serviceCandidates(options, key, fqn, shortName),
            context
        );
    }

    /**
     * Resolves a fresh instance: new() on the Container (bypasses the
     * instance cache); on the legacy Di, get() for unregistered or
     * non-shared services, and a rebuild from the definition for shared
     * services (Di::get() would return the cached instance). On Di, an
     * unregistered but existing class is still built via the class builder.
     *
     * @throws ContainerException
     */
    public static function resolveFresh(var container, string name) -> object
    {
        var definition, e, fresh, service;

        self::ensureContainer(container);

        if (container instanceof Collection) {
            if (true !== container->has(name)) {
                throw new ContainerException(
                    "Cannot resolve a fresh '" . name
                    . "': it is not bound in the container"
                );
            }

            return container->{"new"}(name);
        }

        if (true !== container->has(name) && !class_exists(name)) {
            throw new ContainerException(
                "Cannot resolve a fresh '" . name
                . "': it is not registered in the Di and is not an existing class"
            );
        }

        try {
            if (true === container->has(name)) {
                let service = container->getService(name);

                /**
                 * A shared service is cached by the Di. Gates carry
                 * per-activation state, so build a new instance from the same
                 * definition. A definition that is an already built object
                 * can never be fresh.
                 */
                if (true === service->isShared()) {
                    let definition = service->getDefinition();

                    if (typeof definition === "object" && !(definition instanceof Closure)) {
                        throw new ContainerException(
                            "Cannot resolve a fresh '" . name
                            . "': it is registered in the Di as a shared instance"
                        );
                    }

                    let fresh = new Service(definition, false);

                    return fresh->resolve(null, container);
                }
            }

            return container->get(name);
        } catch DiException, e {
            throw new ContainerException(
                "Failed to resolve '" . name . "' from the Di container",
                0,
                e
            );
        }
    }

    /**
     * Builds the ordered candidate list for a framework service:
     * an explicit override from options['services'][key] if present,
     * otherwise the interface FQN followed by the conventional short name.
     *
     * @param array<string, mixed> $options
     *
     * @return list<string>
     */
    public static function serviceCandidates(
        array options,
        string key,
        string fqn,
        string shortName
    ) -> array {
        var services, override;

        if (fetch services, options["services"]) {
            if (typeof services === "array" && fetch override, services[key]) {
                if (typeof override === "string" && override !== "") {
                    return [override];
                }
            }
        }

        return [fqn, shortName];
    }

    /**
     * Resolves a shared instance: get() on the Container; getShared() on the
     * legacy Di. Legacy-Di failures are normalized to a Container exception
     * with the original chained as the cause.
     *
     * @throws ContainerException
     */
    private static function resolveShared(var container, string name) -> object
    {
        var e;

        if (container instanceof Collection) {
            return container->get(name);
        }

        try {
            return container->getShared(name);
        } catch DiException, e {
            throw new ContainerException(
                "Failed to resolve '" . name . "' from the Di container",
                0,
                e
            );
        }
    }
}
